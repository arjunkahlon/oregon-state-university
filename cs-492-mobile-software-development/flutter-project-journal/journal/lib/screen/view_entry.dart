import 'package:flutter/material.dart';
import 'package:journal/model/journal_entry.dart';
import 'package:journal/db/service_entry.dart';
import 'package:journal/widget/entry_detail.dart';

class ViewEntry extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    int id = ModalRoute.of(context).settings.arguments;
    Future<JournalEntry> futureJournalEntry = ServiceEntry.retrieveEntry(id);

    return Scaffold(
      appBar: AppBar(
        title: Text('Entry Details'),
        centerTitle: true,
      ),
      body: FutureBuilder(
        future: futureJournalEntry,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            JournalEntry journalEntry = snapshot.data;
            return EntryDetail(journalEntry: journalEntry);
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

