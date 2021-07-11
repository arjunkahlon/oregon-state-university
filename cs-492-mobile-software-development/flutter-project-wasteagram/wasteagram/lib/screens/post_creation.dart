import 'dart:io';
import 'package:flutter/material.dart';
import 'package:geolocator/geolocator.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:rounded_loading_button/rounded_loading_button.dart';
import 'package:wasteagram/models/post.dart';
import 'package:form_field_validator/form_field_validator.dart';

class PostCreation extends StatefulWidget {
  @override
  _PostCreationState createState() => _PostCreationState();
}

class _PostCreationState extends State<PostCreation> {
  final postFormKey = GlobalKey<FormState>();
  TextEditingController quantityController = TextEditingController();
  RoundedLoadingButtonController buttonController =
      RoundedLoadingButtonController();
  bool isSubmitted = false;

  // RequiredValidator quantityRequiredValidator = RequiredValidator(errorText: 'Please enter wasted items');
  // RangeValidator quantityRangeValidator = RangeValidator(min: 1, errorText: 'Invalid Quantity');
  MultiValidator quantityValidator = MultiValidator([
    RequiredValidator(errorText: 'Please enter wasted items'),
    RangeValidator(min: 1, max: double.infinity, errorText: 'Invalid Quantity')
  ]);

  @override
  Widget build(BuildContext context) {
    Map argument = ModalRoute.of(context).settings.arguments;
    File imageFile = File(argument['filePath']);
    return Scaffold(
      appBar: AppBar(
        title: Text('Enter Wasted Quantity'),
      ),
      body: Form(
        key: postFormKey,
        child: Padding(
          padding: const EdgeInsets.all(14.0),
          child: Column(
            children: [
              Image.file(imageFile),
              SizedBox(height: 16,),
              TextFormField(
                controller: quantityController,
                validator: quantityValidator,
                keyboardType: TextInputType.number,
                decoration: InputDecoration(labelText: 'quantity'),
                autovalidateMode: AutovalidateMode.onUserInteraction,
              )
            ],
          ),
        ),
      ),
      bottomNavigationBar: AbsorbPointer(
        absorbing: isSubmitted,
        child: Padding(
          padding: const EdgeInsets.all(30.0),
          child: RoundedLoadingButton(
            controller: buttonController,
            child: Icon(
              Icons.cloud,
              size: 30,
              color: Colors.white,
            ),
            onPressed: () {
              if(postFormKey.currentState.validate()){
                setState(() async {
                  await uploadPost(imageFile);
                  await buttonController.success();
                  Navigator.pushNamed(context, '/postList');
                });
              } else {
                buttonController.reset();
              }

            },
          ),
        ),
      ),
    );
  }

  Future<void> uploadPost(File imageFile) async {
    FirebaseStorage storage = FirebaseStorage.instance;
    String fileName = DateTime.now().toString();
    TaskSnapshot taskSnapshot =
        await storage.ref('/WastedFoods/$fileName').putFile(imageFile);
    print(await taskSnapshot.ref.getDownloadURL());
    Position position = await getPosition();
    print('${position.latitude} | ${position.longitude}');
    Post newPost = Post(
        DateTime.now(),
        await taskSnapshot.ref.getDownloadURL(),
        int.parse(quantityController.text),
        position.longitude,
        position.latitude);
    Post.createPost(newPost);
  }

  Future<Position> getPosition() async {
    //Code Source: https://pub.dev/packages/geolocator

    bool serviceEnabled;
    LocationPermission permission;

    // Test if location services are enabled.
    serviceEnabled = await Geolocator.isLocationServiceEnabled();
    if (!serviceEnabled) {
      // Location services are not enabled don't continue
      // accessing the position and request users of the
      // App to enable the location services.
      return Future.error('Location services are disabled.');
    }

    permission = await Geolocator.checkPermission();
    if (permission == LocationPermission.denied) {
      permission = await Geolocator.requestPermission();
      if (permission == LocationPermission.deniedForever) {
        // Permissions are denied forever, handle appropriately.
        return Future.error(
            'Location permissions are permanently denied, we cannot request permissions.');
      }

      if (permission == LocationPermission.denied) {
        // Permissions are denied, next time you could try
        // requesting permissions again (this is also where
        // Android's shouldShowRequestPermissionRationale
        // returned true. According to Android guidelines
        // your App should show an explanatory UI now.
        return Future.error('Location permissions are denied');
      }
    }

    // When we reach here, permissions are granted and we can
    // continue accessing the position of the device.
    return await Geolocator.getCurrentPosition();
  }
}
