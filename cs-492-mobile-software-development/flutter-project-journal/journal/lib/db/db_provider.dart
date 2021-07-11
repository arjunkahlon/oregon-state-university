import 'dart:io';
import 'package:flutter/services.dart';
import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';
import 'package:sqflite/sqlite_api.dart';


class DBProvider {
  static Database _database;

  static Future <Database> get database async {
    var dbPath = await getDatabasesPath();
    print('Database path is $dbPath');
    if (_database == null) {
      _database = await initDB();
    }
    return _database;
  }

  static Future <Database> initDB() async {
    final dbPath = join(await getDatabasesPath(), 'journal.sqlite3.db');
    return await openDatabase(dbPath, onCreate: (database, version) async {await createSchema(database);},version: 1);
  }

  static Future <void> createSchema(Database database) async {
    var schemaCreationCommand = await loadCommandFromFile();
    await database.execute(schemaCreationCommand);
  }

  static Future <String> loadCommandFromFile() async {
    String command = await rootBundle.loadString('assets/schema_1.sql.txt');
    print('Loaded Command: $command');
    return command;
  }

}