<?php
	/*------------------------------------------------------------------*/
    // Abre a conexão com o banco de dados
    function connectDB(){
		///Database variables
		$bdServer = 'localhost';
		$bdUser = 'root';
		$bdPassword = 'root';
		$bdName = 'IA_demo';
		///Connection
		$_connection = mysqli_connect($bdServer, $bdUser, $bdPassword, $bdName);
		if (mysqli_connect_errno($_connection)) {
			echo "Problemas para conectar no banco. Verifique os dados!";
			die();
		}
		return $_connection;
	}
	
	/*------------------------------------------------------------------*/
	/// Devolve os dados contidos na tabela 
	function searchData($_connection, $_limit) {
		$sqlSelect = 'SELECT * FROM `demo_LDR` ORDER BY id DESC LIMIT ' . $_limit . ' ';
		$result = mysqli_query($_connection, $sqlSelect);
		$data = array();
		while ($line = mysqli_fetch_assoc($result)) {
			$data[] = $line;
		}
		return $data;
	}
	
	/*------------------------------------------------------------------*/
	// Insere os dados na tabela
	function insertData($_connection, $_data){
		$sqlInsert = "
			INSERT INTO demo_LDR
			(LDR1, LDR2, button)
			VALUES
			(
				'{$_data['LDR1']}',
				'{$_data['LDR2']}',
				'{$_data['button']}'
			)
		";

		echo "Insert result: ";
		if (mysqli_query($_connection, $sqlInsert)) return "sucess";
		else return "fail";
	}
	
    /*------------------------------------------------------------------*/
    // Fecha a conexão com o banco de dados
	function closeDB($_conexão){
		mySQLi_close ($_conexão);
    }
?>
