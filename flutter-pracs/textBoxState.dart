import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: TextBoxStateManagementApp(),
    );
  }
}

class TextBoxStateManagementApp extends StatefulWidget {
  @override
  _TextBoxStateManagementAppState createState() =>
      _TextBoxStateManagementAppState();
}

class _TextBoxStateManagementAppState extends State<TextBoxStateManagementApp> {
  // TextEditingController to manage the state of the TextField
  TextEditingController _textController = TextEditingController();

  @override
  void dispose() {
    // Dispose the TextEditingController to avoid memory leaks
    _textController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('TextBox State Management'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            TextField(
              controller: _textController,
              decoration: InputDecoration(
                labelText: 'Enter Text',
                border: OutlineInputBorder(),
              ),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: () {
                // Get the current text from the TextField
                String enteredText = _textController.text;

                // Display a dialog with the entered text
                showDialog(
                  context: context,
                  builder: (context) {
                    return AlertDialog(
                      title: Text('Entered Text'),
                      content: Text(enteredText),
                      actions: [
                        TextButton(
                          onPressed: () {
                            // Close the dialog
                            Navigator.pop(context);
                          },
                          child: Text('OK'),
                        ),
                      ],
                    );
                  },
                );
              },
              child: Text('Show Entered Text'),
            ),
          ],
        ),
      ),
    );
  }
}
