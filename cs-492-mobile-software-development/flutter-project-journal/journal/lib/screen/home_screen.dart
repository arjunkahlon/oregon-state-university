import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:journal/main.dart';
import 'package:journal/screen/entries.dart';
import 'package:journal/db/service_entry.dart';
import 'package:journal/model/journal_entry.dart';

class HomeScreen extends StatefulWidget {
  bool isDarkTheme;

  HomeScreen(this.isDarkTheme);

  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {

  Future<List<JournalEntry>> journalEntries;
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          'Journal Entries',
          style: TextStyle(color: Colors.white),
        ),
        centerTitle: true,
      ),
      endDrawer: Drawer(
        child: ListView(
          children: [
            Container(
              height: 50,
              child: DrawerHeader(
                child: Text('Settings'),
              ),
            ),
            ListTile(
              leading: Icon(Icons.nightlight_round),
              title: Text('Dark Theme'),
              trailing: Switch(
                value: widget.isDarkTheme,
                onChanged: (isDark) {
                  String themeName = isDark ? 'Dark' : 'Light';
                  saveTheme(themeName);
                  setState(() {
                    print('Switched to $themeName');
                    widget.isDarkTheme = isDark;
                    JournalAppState journalAppState = context.findAncestorStateOfType<JournalAppState>();
                    journalAppState.setState(() {
                      JournalApp journalApp = context.findAncestorWidgetOfExactType();
                      journalApp.themeMode = isDark ? ThemeMode.dark : ThemeMode.light;
                    });
                  });
                },
              ),
            ),
          ],
        ),
      ),
      body: Entries(journalEntries),
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.add),
        onPressed: (){
          Navigator.pushNamed(context, '/addEntry').then((value) => setState((){
            journalEntries = ServiceEntry.retrieveEntries();
          }));
        },
      ),
    );
  }
}

void saveTheme(String themeName) async {
  SharedPreferences preference = await SharedPreferences.getInstance();
  preference.setString('Theme Name', themeName);

}