class JournalEntry {
  int id;
  String title;
  String body;
  int rating;
  DateTime date;

  JournalEntry(this.id, this.title, this.body, this.rating, this.date);

  JournalEntry.fromMap(Map <String,dynamic> map){
    this.id = map['id'];
    this.title = map['title'];
    this.body = map['body'];
    this.rating = map['rating'];
    this.date = DateTime.parse(map['date']);

  }

}
