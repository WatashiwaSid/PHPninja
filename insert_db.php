<?php
$servername = "localhost";
$username = "root";
$pass = "";
$db = "gehu";

$con = mysqli_connect($servername, $username, $pass, $db);

if($con)
{
    try
    {
        mysqli_query($con,
         "CREATE TABLE IF NOT EXISTS courses(
          course_id INT(6) primary key, 
          course_name VARCHAR(30) NOT NULL, 
          duration INT(2))");
        echo "Table Created";
    }
    catch(Exception)
    {
        echo "Could not create table";
    }

    try
    {
        mysqli_query($con, 
        "INSERT INTO courses(course_id, course_name, duration)
        VALUES (1234, 'BCA', 3), (4455, 'BTECH', 4)");
        echo "Values inserted";
    }
    catch(Exception)
    {
        echo "Could not insert values.\n";
    }
}
?>