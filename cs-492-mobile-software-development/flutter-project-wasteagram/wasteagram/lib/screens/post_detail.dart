import 'package:flutter/material.dart';
import 'package:wasteagram/models/post.dart';
import 'package:intl/intl.dart';

class PostDetail extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    Map argument = ModalRoute.of(context).settings.arguments;
    Future<Post> futurePost = Post.getPost(argument['id']);
    return Scaffold(
      appBar: AppBar(
        title: Text('Post Detail'),
      ),
      body: FutureBuilder(
        future: futurePost,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            Post post = snapshot.data;
            return Center(
              child: Column(

                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Padding(
                    padding: const EdgeInsets.all(12.0),
                    child: Text('${DateFormat.yMMMEd().format(post.date)}', style: TextStyle(fontSize: 30),),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(12.0),
                    child: Image.network(post.imageURL),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text('Quantity: ${post.quantity}', style: TextStyle(fontSize: 20),),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text('Location: (${post.latitude},${post.longitude})', style: TextStyle(fontSize: 15),),
                  ),
                ],
              ),
            );
          } else {
            return Center(
              child: CircularProgressIndicator(),
            );
          }
        },
      ),
    );
  }
}
