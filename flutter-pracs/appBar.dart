import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: PreferredSize(
          preferredSize: const Size.fromHeight(100.0),
          child: MyAppBar(),
        ),
        body: const Center(
          child: Text('Your App Content Goes Here'),
        ),
      ),
    );
  }
}

class MyAppBar extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return AppBar(
      toolbarHeight: 100.0,
      backgroundColor: Colors.red,
      title: const Text(
        'My App',
        style: TextStyle(color: Colors.white),
      ),
      leading: PopupMenuButton<String>(
        onSelected: (value) {
          // Handle menu item selection
          print(value);
        },
        itemBuilder: (BuildContext context) {
          return {'Home', 'Contact Us', 'About'}.map((String choice) {
            return PopupMenuItem<String>(value: choice, child: Text(choice));
          }).toList();
        },
      ),
      actions: [
        IconButton(
          icon: const Icon(Icons.search),
          onPressed: () {
            // Add your search functionality here
          },
        ),
        IconButton(
          icon: const Icon(Icons.camera),
          onPressed: () {
            // Add your camera functionality here
          },
        ),
        IconButton(
          icon: const Icon(Icons.settings),
          onPressed: () {
            // Add your settings functionality here
          },
        ),
      ],
    );
  }
}
