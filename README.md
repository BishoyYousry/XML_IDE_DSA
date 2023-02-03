# Data structures project # 

# Aim #
This project working on developing a GUI based program to parse and visualize an XML file representing users in a social network
, Each user has id (unique), name, list of posts, list of followers.Each post has text and list of topics.

# project description # 

- In this project we will work on some processes on the xml file like :

   1- Formatting (Prettifying) the XML: the XML file should be well formatted by keeping the 
   indentation for each level.

   2- Converting XML to JSON: JSON (Javascript Object Notation) is another format that is used 
   to represent data as It’s helpful to convert the XML into JSON, especially when using 
   javascript as there’s tons of libraries and tools that use json notation.  

   3- Minifying the XML file: Since spaces and newlines (\n) are actually characters that can 
   increase the size of an XML document. This feature should aim at decreasing the size of 
   an XML file (compressing it) by deleting the whitespaces and indentations.

   4- Compressing the data in the XML/JSON file: You should come-up with a way to reduce the 
   size of the file using a data compression technique.

   5- Decompressing the compressed data to return to its original format.

   6- detecting and visually show any errors in consistency & The program is also be able to solve the errors. 

- In our system the XML file will represent users in a social network
  Each user has id (unique), name, list of posts, list of followers.
  Each post has text and list of topics,so we will : 

    1- represent the users data using the graph data structure: the XML file will represent the 
  users data in a social network (their posts, followers, ...etc). Then we will build a graph relation between the user that looks like the graph 
  beneath.

    2- do Network analysis: by representing the network using the graph data structure, we can 
  extract some important data:

        - who is the most influencer user (has the most followers)

        - who is the most active user (connected to lots of users)

        - the mutual followers between 2 users

        - for each user, suggest a list of users to follow (the followers of his followers)
     3- do  Post search: given a specific word or topic, get the posts where this word or topic was 
  mentioned.

- finally we will build qt application to interface with our xml application and to : 

     1- allow the user to choose the XML file that will be used or enter the xml 
     manually in a text area

     2- allow viewing the input XML and the output of each operation as much as 
     possible

     3- allow the user to save the results of the operations to a new file.

# snapshots # 
![format](https://user-images.githubusercontent.com/93954411/216642107-c3bd4803-966f-452e-9c58-dac4159036f1.png)
![minifying](https://user-images.githubusercontent.com/93954411/216642627-329db6d6-9ab0-428b-b13d-782466a014f7.png)
![xml_to_json](https://user-images.githubusercontent.com/93954411/216642708-bea32fb3-2745-49f0-80a6-4d81a8745af4.png)
![compress](https://user-images.githubusercontent.com/93954411/216642781-7d12f87d-d0ec-4aed-8efc-9a276ce31c48.png)
![Error_list](https://user-images.githubusercontent.com/93954411/216642908-74252613-77cc-484c-977d-77b3696db730.png)
![Error_solve](https://user-images.githubusercontent.com/93954411/216642944-a8a10519-7b37-41ef-b9ae-62c71a12b63d.png)

# setup #
To run this project, you need only to pull the .exe file and run it. 

# live demo # 
To see live demo for project, follow this link : https://drive.google.com/drive/folders/1043FIH-FQKQDvbfzJoU6NmGXaGf6bnSo


# contributors # 
Zeyad Mohamed zeyadmohamedasu@gmail.com

Bishoy Yousry 1900733@eng.asu.edu.eg

Hassan Khaled Hassankhaled006@gmail.com

Omar karam omar.karam771@gmail.com

Yasmeen abdelrazek yasmeenelkhateb49@gmail.com

# license & copyright #
© Software Team ,Faculty Of Engineering Ain Shams University Cairo

​ Licensed under the MIT License