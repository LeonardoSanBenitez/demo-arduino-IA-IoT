<?php
	include "dataBase.php";
	date_default_timezone_set('America/Sao_Paulo');

	if (isset($_GET['LDR1'])) {
		$_buffer = array();
		$_buffer['LDR1'] = $_GET['LDR1'];
        $_buffer['LDR2'] = $_GET['LDR2'];
        $_buffer['button'] = $_GET['button'];

		//test URL: demo/API_data_receive.php?LDR1=150&LDR2=250&button=1

		
		$connection = connectDB();
		echo insertData($connection, $_buffer);
		closeDB($connection);
	}
?>