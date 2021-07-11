import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:wasteagram/screens/post_list.dart';
import 'package:wasteagram/screens/post_detail.dart';
import 'package:wasteagram/screens/post_creation.dart';

void main() async{
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(WasteagramApp());
}

class WasteagramApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(initialRoute: '/postList', routes: {
      '/postList': (context) => PostList(),
      '/postDetail': (context) => PostDetail(),
      '/postCreation': (context) => PostCreation(),
    },);
  }
}
