import 'package:cloud_firestore/cloud_firestore.dart';

class Post {
  DateTime date;
  String imageURL;
  int quantity;
  double longitude;
  double latitude;
  String id;

  Post(this.date, this.imageURL, this.quantity, this.longitude, this.latitude);

  Post.fromMap(Map<String, dynamic> data) {
    date = data['date'].toDate();
    imageURL = data['imageURL'];
    quantity = data['quantity'];
    longitude = data['longitude'];
    latitude = data['latitude'];
    id ??= data['id'];
  }

  static CollectionReference postsCollectionRef =
      FirebaseFirestore.instance.collection('posts');

  static Future<List<Post>> getPosts() async {
    QuerySnapshot postsSnapshot =
        await postsCollectionRef.orderBy('date', descending: true).get();
    List<Post> posts = postsSnapshot.docs.map((DocumentSnapshot postSnapshot) {
      Map data = postSnapshot.data();
      data['id'] = postSnapshot.id;
      return Post.fromMap(data);
    }).toList();
    return posts;
  }

  static Future<DocumentReference> createPost(Post post) async {
    return postsCollectionRef.add({
      'date': post.date,
      'imageURL': post.imageURL,
      'quantity': post.quantity,
      'latitude': post.latitude,
      'longitude': post.longitude,
    });
  }

  static Future<Post> getPost(String id) async {
    DocumentSnapshot postSnapshot = await postsCollectionRef.doc(id).get();
    return Post.fromMap(postSnapshot.data());
  }
}
