# Setup do website

Hospedado em 000webhostapp (free)

Linguagens e tecnologias:
* HTML: para diagramar a página
* CSS: aplica estilos (cores, tamanhos, etc)
* Javascript and VueJS framework: requisita os dados e atualiza a tabela
* PHP: faz a API (Application Programming Interface) para receber e buscar os dados
* SQL: linguagem para interagir com o Banco de Dados
* MySQL: o Banco de Dados em sí (software)

Palavras chaves:
* Single Page Application: a página atualiza sem precisar dar F5
* AJAX: técnica para buscar os dados de forma assíncrona
* Cloud Computing
* Responsive web design


# Setup do Banco de Dados

Criando o DB:

```
CREATE TABLE `demo_LDR` ( 
    `id` INT NOT NULL AUTO_INCREMENT,
    `LDR1` INT NULL ,
    `LDR2` INT NULL ,
    `button` INT NULL , 
    
    PRIMARY KEY (`id`)
)
```SQL