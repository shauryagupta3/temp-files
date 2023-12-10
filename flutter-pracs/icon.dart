import 'dart:ui';

import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      //Scaffold Widget
      home: Scaffold(
        appBar: AppBar(
          title: const Text('GFG'),
        ),
        // body: const Center(child: Text('Hello Guyss!!',textAlign: TextAlign.center,style:TextStyle(fontSize: 50,color: Colors.yellow,fontStyle: FontStyle.italic,letterSpacing: 8,wordSpacing: 20)),
        body: const Center(
            child:
                Icon(Icons.directions_transit, size: 170, color: Colors.blue)),
      ),
    );
  }
}
