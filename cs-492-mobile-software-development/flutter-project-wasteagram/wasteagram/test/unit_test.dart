import 'package:test/test.dart';
import 'package:wasteagram/models/post.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

void main() {
  test('Test Constructor', (){
    final date = DateTime.now();
    final url = 'http://imgsrc8239.com';
    final quantity = 4;
    final latitude = 45.214;
    final longitude = 143.535;

    Post post = Post(date, url, quantity, longitude, latitude);

    expect(post.quantity, quantity);
    expect(post.latitude, latitude);

  });

  test('Test Named Constructor', (){
    final date = Timestamp.fromDate(DateTime.now());
    final url = 'http://imgsrc8239.com';
    final quantity = 4;
    final latitude = 45.214;
    final longitude = 143.535;

    Post post = Post.fromMap({
      'date': date,
      'imageURL': url,
      'quantity': quantity,
      'latitude': latitude,
      'longitude': longitude,
    });

    expect(post.imageURL, url);
    expect(post.longitude, longitude);

  });
}