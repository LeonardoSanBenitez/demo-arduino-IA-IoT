# Setup do servidor

Amazon Web Services (gratuito no primeiro ano)

Instância básica EC2 com o stack LAMP (Linux, Apache, MySQL, PHP) instalado: ver [este tutorial](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ec2-lamp-amazon-linux-2.html)

Linguagens e tecnologias:
* HTML: para diagramar a página
* CSS: aplica estilos (cores, tamanhos, etc)
* Javascript and VueJS framework: requisita os dados e atualiza a tabela
* PHP: faz a API (Application Programming Interface) para receber e buscar os dados
* SQL: linguagem para interagir com o Banco de Dados
* MySQL: o Banco de Dados em sí (software)
* PHPmyAdming: software para acessar graficamente o banco de dados (pelo browser)

Palavras chaves:
* Single Page Application: a página atualiza sem precisar dar F5
* AJAX: técnica para buscar os dados de forma assíncrona
* Cloud Computing
* Responsive web design
* IoT: microcontrolador enviado dados pra um servidor

# Setup do banco de dados

Crie o banco de dados: lado esquerdo do PHPmyAdmin, *new table*, lado eu dei o nome *IA_demo*

Crie a tabela para organizar os dados:

```
CREATE TABLE `demo_LDR` ( 
    `id` INT NOT NULL AUTO_INCREMENT,
    `LDR1` INT NULL ,
    `LDR2` INT NULL ,
    `button` INT NULL , 
    
    PRIMARY KEY (`id`)
)
​```SQL
```

# Setup do website

Envie os arquivos usando scp. Exemplo:

`scp -i <chaveLocal> <arquivoLocal> ec2-user@<publicDNS>:/var/www/html/demo/`

Teste tudo inserindo um dado fake, digintado no navegador (ou seja, fazendo um get request):

`<publicDNS>/demo/API_data_receive.php?LDR1=150&LDR2=250&button=1`