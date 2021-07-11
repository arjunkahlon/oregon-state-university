import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:wasteagram/models/post.dart';
import 'package:image_picker/image_picker.dart';
import 'package:intl/intl.dart';

class PostList extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    Future<List<Post>> futureAllPosts = Post.getPosts();
    return Scaffold(
      appBar: AppBar(
        title: FutureBuilder(future: futureAllPosts, builder: (context, snapshot){
          if (snapshot.hasData) {
            List<Post> listPosts = snapshot.data;
            var sumOfQuantity = listPosts.fold(0, (accumulateValue, post) => accumulateValue + post.quantity);
            return Text('Wasteagram - $sumOfQuantity');
          }else {
            return Text('Wasteagram');
          }
        },),
        centerTitle: true,
      ),
      body: FutureBuilder(
        future: futureAllPosts,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            List<Post> posts = snapshot.data;
            if (posts.length == 0) {
              return Center(
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    CircularProgressIndicator(),
                    SizedBox(height: 15,),
                    Text('No Wasted Items to Display')
                  ],
                ),
              );
            } else {
              return ListView.builder(
                  itemCount: posts.length,
                  itemBuilder: (context, index) {
                    return GestureDetector(
                      onTap: () {
                        Navigator.pushNamed(context, '/postDetail',
                            arguments: {'id': posts[index].id});
                      },
                      child: Padding(
                        padding: const EdgeInsets.fromLTRB(18.0, 12.0, 24.0, 12.0),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.spaceBetween,
                          children: [
                            Text(DateFormat.yMMMEd().format(posts[index].date), style: TextStyle(fontSize: 20),),
                            Text(posts[index].quantity.toString(), style: TextStyle(fontSize: 25),),
                          ],
                        ),
                      ),
                    );
                  });
            }
          } else {
            return Center(
              child: CircularProgressIndicator(),
            );
          }
        },
      ),
      bottomNavigationBar: Padding(
        padding: const EdgeInsets.all(25.0),
        child: ElevatedButton(
          style: ElevatedButton.styleFrom(
            shape: CircleBorder(),
            primary: Colors.blue,
            padding: EdgeInsets.all(15),
          ),
          child: Icon(
            Icons.add,
            size: 45,
          ),
          onPressed: () async {
            ImagePicker picker = ImagePicker();
            PickedFile pickedFile =
                await picker.getImage(source: ImageSource.gallery);
            if (pickedFile != null) {
              Navigator.pushNamed(context, '/postCreation',
                  arguments: {'filePath': pickedFile.path});
            }
          },
        ),
      ),
    );
  }
}
