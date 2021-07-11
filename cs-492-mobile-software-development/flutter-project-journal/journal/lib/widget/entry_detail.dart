import 'package:flutter/material.dart';
import 'package:journal/model/journal_entry.dart';

class EntryDetail extends StatelessWidget {
  const EntryDetail({
    Key key,
    @required this.journalEntry,
  }) : super(key: key);

  final JournalEntry journalEntry;

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Padding(
        padding: const EdgeInsets.all(15.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            //Text('Title', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, ),),
            //SizedBox(height: 20,),
            Text(journalEntry.title, style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold, ),),
            SizedBox(height: 20,),
            //Text('Body', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, ),),
            SizedBox(height: 20,),
            Text(journalEntry.body, style: TextStyle(fontSize: 20, ),),
            SizedBox(height: 20,),
            Text('Rating - ${journalEntry.rating.toString()}', style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold, ),),
            //SizedBox(height: 20,),
            //Text(journalEntry.rating.toString()),
          ],
        ),
      ),
    );
  }
}