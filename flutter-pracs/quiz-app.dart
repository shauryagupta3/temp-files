import 'package:flutter/material.dart';
import 'Questions.dart';

void main() => runApp(const MaterialApp(
      home: MyApp(),
      debugShowCheckedModeBanner: false,
    ));

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  var score = 0;
  var n = 0;
  // ignore: non_constant_identifier_names
  List que_list = [
    Questions("1.MS Word is a hardware", false),
    Questions("2.CPU controls only input data of the computer.", false),
    Questions("3.CPU stands for Central Processing Unit.", true),
    Questions(
        "4.Freeware is software that is available for use at no monetary cost.",
        true),
  ];

  void checkAnswer(bool choice, BuildContext ctx) {
    if (choice == que_list[n].ans) {
      score = score + 1;
      const snackbar = SnackBar(
        content: Text("Correct Answer"),
        duration: Duration(milliseconds: 500),
        backgroundColor: Colors.green,
      );
      ScaffoldMessenger.of(ctx).showSnackBar(snackbar);
    } else {
      const snackbar = SnackBar(
        content: Text("Wrong Answer"),
        duration: Duration(milliseconds: 500),
        backgroundColor: Colors.red,
      );
      ScaffoldMessenger.of(ctx).showSnackBar(snackbar);
    }
    setState(() {
      if (n < que_list.length - 1) {
        n = n + 1;
      } else {
        final snackbar = SnackBar(
          content: Text("Quiz Completed Score $score/4"),
          duration: Duration(seconds: 5),
          backgroundColor: Colors.blueAccent,
        );
        ScaffoldMessenger.of(ctx).showSnackBar(snackbar);
        reset();
      }
    });
  }

  void reset() {
    setState(() {
      n = 0;
      score = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.brown,
        title: const Text("Simple Quiz"),
        centerTitle: true,
      ),
      body: Builder(
        builder: (ctx) => Container(
          padding: const EdgeInsets.symmetric(vertical: 20, horizontal: 15),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: <Widget>[
                  Text(
                    "Score : $score/4 ",
                    style: const TextStyle(
                      color: Colors.brown,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  InkWell(
                    onTap: () => reset(),
                    child: const Text(
                      "Reset ",
                      style: TextStyle(
                        color: Colors.red,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ],
              ),
              const SizedBox(
                height: 15,
              ),
              Container(
                height: 100,
                width: double.infinity,
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(15.0),
                  border: Border.all(color: Colors.brown),
                ),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: <Widget>[
                    Text(
                      que_list[n].que,
                      style: const TextStyle(fontSize: 15.0),
                    )
                  ],
                ),
              ),
              const SizedBox(
                height: 15,
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: <Widget>[
                  ElevatedButton(
                    child: const Text(
                      "True",
                      style: TextStyle(color: Colors.brown, fontSize: 20.0),
                    ),
                    onPressed: () => checkAnswer(true, ctx),
                  ),
                  ElevatedButton(
                    child: const Text(
                      "False",
                      style: TextStyle(color: Colors.brown, fontSize: 20.0),
                    ),
                    onPressed: () => checkAnswer(false, ctx),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}

// Questions.dart
class Questions {
  String que;
  bool ans;
  Questions(this.que, this.ans);
}
