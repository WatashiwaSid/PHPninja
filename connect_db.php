<?php
$servername = "localhost";
$username = "root";
$pass = "";

$con = mysqli_connect($servername, $username, $pass);

if($con)
{
    try
    {
        mysqli_query($con, "CREATE DATABASE IF NOT EXISTS gehu");
        echo "Database successfully created";
    }

    catch(Exception)
    {
        echo "Could not create database";
    }
}
?>
