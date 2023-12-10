import 'package:flutter/material.dart';

void main(List<String> args) {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(home: MyHomePage());
  }
}

class MyHomePage extends StatefulWidget {
  MyHomePageState createState() => new MyHomePageState();
}

class MyHomePageState extends State<MyHomePage> {
  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text('On Tap'),
        centerTitle: true,
      ),
      body: new Center(
        child: GestureDetector(
          onDoubleTap: () {
            print('Double Tapped');
          },
          onTap: () {
            print('Single Tap');
          },
          child: Container(
            height: 50,
            width: 120,
            padding: EdgeInsets.all(10),
            decoration: BoxDecoration(
                color: Colors.blue, borderRadius: BorderRadius.circular(15)),
            child: Center(child: Text('Click Me')),
          ),
        ),
      ),
    );
  }
}
