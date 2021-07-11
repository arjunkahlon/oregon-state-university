import 'package:journal/db/db_provider.dart';
import 'package:journal/model/journal_entry.dart';

class ServiceEntry{
  static String tableName = 'journal_entries';

  static Future<int> addEntry(JournalEntry journalEntry) async {
    final db = await DBProvider.database;
    final sql = '''
    INSERT INTO ${ServiceEntry.tableName}
      (
        title,
        body,
        rating,
        date
      )
      VALUES
      (
        "${journalEntry.title}",
        "${journalEntry.body}",
        ${journalEntry.rating},
        "${journalEntry.date}"
      )
 
    ''';
    final recordID = await db.rawInsert(sql);
    return recordID;
  }

  static Future<List<JournalEntry>> retrieveEntries() async {
    final db = await DBProvider.database;
    final sql = 'SELECT * FROM ${ServiceEntry.tableName}';
    final data = await db.rawQuery(sql);
    List<JournalEntry> journalEntries = List();
    for (final entry in data) {
      JournalEntry journalEntry = JournalEntry.fromMap(entry);
      journalEntries.add(journalEntry);
    }
    return journalEntries;
  }

  static Future<JournalEntry> retrieveEntry(int id) async {
    final db = await DBProvider.database;
    final sql = 'SELECT * FROM ${ServiceEntry.tableName} WHERE id = $id';
    final data = await db.rawQuery(sql);

    JournalEntry entry = JournalEntry.fromMap(data[0]);
    return entry;
  }



}