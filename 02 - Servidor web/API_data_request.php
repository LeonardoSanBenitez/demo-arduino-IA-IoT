<?php
include "dataBase.php";

$connection = connectDB();
print json_encode(searchData($connection, 5));
closeDB($connection);

?>
