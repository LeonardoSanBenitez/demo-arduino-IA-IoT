<!DOCTYPE html>
<html lang="pt-br">
	<head>
		<!-- Definições Iniciais -->
		<title>IA demo</title>
		<meta charset="utf-8" />
		<meta name="description"			content="Plataforma de demostração para o curso de Data Science, no Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina." />
		<meta name="keywords"				content="Data Science, Machine Learning, polo embrapii, labsmart, IFSC" />
		<meta name="author"					content="Leonardo Benitez" />
		<meta name="viewport"				content="width=device-width, initial-scale=1" />
		<meta name="robots" 				content="index,follow" />
		<meta http-equiv="content-language"	content="pt-br" />
		<link rel="icon"					href="favicon.ico"  type="shortcut icon" />

		<!-- CSS -->
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" />
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.4.0/css/font-awesome.min.css" />
		<link rel="stylesheet" href="template.css" />
	</head>
	
	<body>
		<div class="geral" id="app">
			<!-- Navbar -->
			<nav class="navbar navbar-default">
				<div class="container-fluid">
					<div class="navbar-header">
						<a class="navbar-brand" href="index.php">Demo</a>
					</div>
				</div>
            </nav>
			
			<!-- Main Content -->
			<div class="container-fluid wrap">
				<!-- Título -->
				<header class="row"><h1>Demonstração LDR</h1></header>
				
				<!-- Tabela -->
				<section id="data-hub" class="row table-responsive">
					<table class="table table-hover">
					  <thead class="thead-light" >
						<tr>
						  <th scope="col">ID</th>
						  <th scope="col">LDR1</th>
						  <th scope="col">LDR2</th>
						  <th scope="col">Button</th>
						</tr>
					  </thead>
					  <tbody>
						<tr v-for="data in json">
						  <td>{{data.id}}</td>
						  <td>{{data.LDR1}}</td>
						  <td>{{data.LDR2}}</td>
						  <td>{{data.button}}</td>
						</tr>
					  </tbody>
					</table>
				</section>	
			</div>
				
			<!-- footer -->
			<footer class="container-fluid rodape"> 
                <div class="row rodape"> 
                    <p>© 2020 Polo de Inovação Embrapii IFSC</p></br>
                    <a class="fa fa-facebook-square"	target="_blanck" href="https://www.facebook.com/peifsc/"></a> 
                    <a class="fa fa-youtube-square"		target="_blanck" href="https://www.youtube.com/channel/UCoy_8UqUguV-mPykB0uIQGA"></a> 
                    <a class="fa fa-linkedin-square"	target="_blanck" href="https://www.linkedin.com/company/poloembrapii-ifsc/about/"></a> 
                    <a class="fa fa-instagram"			target="_blanck" href="https://www.instagram.com/embrapii/"></a> 
                    <a class="fa fa-twitter-square"		target="_blanck" href="https://twitter.com/oficialembrapii?lang=en"></a> 
                </div>
            </footer>
		</div>
		
		<!-- Java Script -->
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
 		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
		<script src="https://cdn.jsdelivr.net/npm/vue"></script>		
 		<script src="vue_controller.js"></script>		
	</body>
</html>