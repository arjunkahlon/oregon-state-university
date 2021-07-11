import 'package:flutter/material.dart';
import 'package:journal/model/journal_entry.dart';
import 'package:journal/db/service_entry.dart';
import 'package:journal/widget/entry_detail.dart';
import 'package:intl/intl.dart';

class Entries extends StatefulWidget {
  Future<List<JournalEntry>> futureJournalEntries;

  Entries(this.futureJournalEntries);

  @override
  _EntriesState createState() => _EntriesState();
}

class _EntriesState extends State<Entries> {
  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    widget.futureJournalEntries = ServiceEntry.retrieveEntries();
  }
  Future<JournalEntry> futureJournalEntry;

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: widget.futureJournalEntries,
        builder: (context, snapshot) {
          if (snapshot.hasData) {
            List<JournalEntry> journalEntries = snapshot.data;
            return buildEntriesView(journalEntries);
          } else {
            return Center(
              child: CircularProgressIndicator(),
            );
          }
        });
  }

  Widget buildEntriesView(List<JournalEntry> journalEntries) {
    if (journalEntries.length == 0) {
      return Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('Welcome!', style: TextStyle(fontSize: 25),),
            Text('', style: TextStyle(fontSize: 20),),

            Icon(
              Icons.book,
              size: 80,
            ),
            //Text('Welcome!', style: TextStyle(fontSize: 25),),
            Text('Journal')
          ],
        ),
      );
    } else {
      return LayoutBuilder(builder: (context, dimensions) {
        if (dimensions.maxWidth >= 500) {
          return Row(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Expanded(
                flex: 2,
                child: ListView.builder(itemCount: journalEntries.length, itemBuilder: (context, index) {
                  return GestureDetector(
                    onTap: () {
                      setState(() {
                        int id = journalEntries[index].id;
                        futureJournalEntry = ServiceEntry.retrieveEntry(id);
                      });
                    },
                    child: ListTile(
                      title: Text(journalEntries[index].title),
                      subtitle: Text(
                        DateFormat('yyyy-MM-dd HH:mm').format(journalEntries[index].date),
                      ),
                    ),
                  );
                }),
              ),
              VerticalDivider(thickness: 3,),
              Expanded(
                flex: 3,
                child: FutureBuilder(future: futureJournalEntry, builder: (context, snapshot){
                  if(snapshot.hasData){
                    JournalEntry journalEntry = snapshot.data;
                    return EntryDetail(journalEntry: journalEntry);
                  }else{
                    return Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: Text('Please Select Entry on Left'),
                    );
                  }
                }),
              ),
            ],
          );
        } else {
          return ListView.builder(
              itemCount: journalEntries.length,
              itemBuilder: (context, index) {
                return GestureDetector(
                  onTap: () {
                    Navigator.pushNamed(context, '/viewEntry',
                        arguments: journalEntries[index].id);
                  },
                  child: ListTile(
                    title: Text(journalEntries[index].title),
                    subtitle: Text(
                      DateFormat('yyyy-MM-dd HH:mm').format(journalEntries[index].date),
                    ),
                  ),
                );
              });
        }
      });
    }
  }
}
