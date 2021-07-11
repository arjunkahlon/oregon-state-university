import 'package:flutter/material.dart';
import 'package:journal/model/journal_entry.dart';
import 'package:journal/db/service_entry.dart';
import 'package:form_field_validator/form_field_validator.dart';

class AddEntry extends StatelessWidget {
  TextEditingController titleController = TextEditingController();
  TextEditingController bodyController = TextEditingController();
  TextEditingController ratingController = TextEditingController();

  RequiredValidator titleValidator =
      RequiredValidator(errorText: 'Invalid Title');
  RequiredValidator bodyValidator =
      RequiredValidator(errorText: 'Invalid Body');
  String ratingValidator(String rating){
    if(['1', '2', '3', '4'].contains(rating)){
      return null;
    }else{
      return 'Invalid Rating';
    }
  }

  final _formKey = GlobalKey<FormState>();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Add Entry'),
        centerTitle: true,
      ),
      body: Form(
        key: _formKey,
        child: Padding(
          padding: const EdgeInsets.all(12.0),
          child: SingleChildScrollView(
            child: Column(
              children: [
                TextFormField(
                  controller: titleController,
                  decoration: InputDecoration(labelText: 'Title'),
                  validator: titleValidator,
                  autovalidateMode: AutovalidateMode.onUserInteraction,
                ),
                SizedBox(
                  height: 15,
                ),
                TextFormField(
                  controller: bodyController,
                  decoration: InputDecoration(labelText: 'Body'),
                  validator: bodyValidator,
                  autovalidateMode: AutovalidateMode.onUserInteraction,
                  maxLines: null,
                ),
                SizedBox(
                  height: 15,
                ),
                TextFormField(
                  controller: ratingController,
                  decoration: InputDecoration(labelText: 'Rating'),
                  autovalidateMode: AutovalidateMode.onUserInteraction,
                  validator: ratingValidator,
                ),
                SizedBox(
                  height: 15,
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: [
                    RaisedButton(
                        child: Text('Cancel'),
                        onPressed: () {
                          Navigator.pop(context);
                        }),
                    SizedBox(
                      width: 50,
                    ),
                    RaisedButton(
                        child: Text('Add'),
                        onPressed: () {
                          if (_formKey.currentState.validate()){
                            saveEntry(titleController.text, bodyController.text,
                                ratingController.text);
                            Navigator.pop(context);
                          }

                        }),
                  ],
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  void saveEntry(String title, String body, String rating) {
    JournalEntry journalEntry =
        JournalEntry(null, title, body, int.parse(rating), DateTime.now());
    ServiceEntry.addEntry(journalEntry);
  }
}
