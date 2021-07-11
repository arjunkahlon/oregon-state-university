import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'screen/home_screen.dart';
import 'package:journal/screen/add_entry.dart';
import 'package:journal/screen/view_entry.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  var themeName = await getTheme();
  ThemeMode themeMode = themeName == 'Dark'?ThemeMode.dark : ThemeMode.light;
  runApp(JournalApp(themeMode), );
}

class JournalApp extends StatefulWidget {
  ThemeMode themeMode;

  JournalApp(this.themeMode);

  @override
  JournalAppState createState() => JournalAppState();
}

class JournalAppState extends State<JournalApp> {
  @override
  Widget build(BuildContext context) {
    bool isDarkTheme = widget.themeMode == ThemeMode.dark ? true : false;
    return MaterialApp(
      initialRoute: '',
      routes: {
        '/home': (context) => HomeScreen(isDarkTheme),
        '/addEntry': (context) => AddEntry(),
        '/viewEntry': (context) => ViewEntry(),
      },
      home: HomeScreen(isDarkTheme),
      // theme: ThemeData.light(),
      // darkTheme: ThemeData.dark(),
      theme: ThemeData.light().copyWith(
        floatingActionButtonTheme:
        FloatingActionButtonThemeData(foregroundColor: Colors.white),
      ),
      darkTheme: ThemeData.dark().copyWith(
        floatingActionButtonTheme:
        FloatingActionButtonThemeData(foregroundColor: Colors.black),
      ),
      themeMode: widget.themeMode,

    );
  }
}



Future<String> getTheme() async{
  SharedPreferences preference = await SharedPreferences.getInstance();
  return preference.getString('Theme Name');
}
