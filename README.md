# Demonstração IoT + IA

Este é uma pequena demonstração do ciclo de vida de um projeto de Machine Learning: 

* Conceber o funcionamento do sistema
* Coletar os dados
* Armazenar e gerenciar os dados
* Treinar um modelo
* Avaliar, interpretar, melhorar

Apesar de simples, o projeto foi estruturado de forma a poder ser facilmente reutilizado e aprimorado

# Microcontrolador

Para implementar o seu basta mudar o endereço IP para o servidor que você subiu, montar os componentes eletrônicos (LDR, resistores e botão) e gravar o arduino

Tecnologias utilizadas:

* Microcontrolador: pequeno processador que consegue ler valores de tensão, se comunicar pela internet, etc
* Linguagem C: linguagem de programação de baixo nível
* Wiring: adaptação da linguagem C
* LDR: Light Dependent Resistor, usado como sensor de luminosidade
* HTTP: protocolo usado para enviar os dados para o servidor

Palavras chaves:

* Sistema embarcado
* IoT: microcontrolador enviado dados pra um servidor
* Telemetria: medir coisas remotamente

# Servidor web

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

## Setup do servidor

Amazon Web Services (gratuito no primeiro ano)

Passo-a-passo para fazer o setup de uma instância basica EC2 (máquina virtual) com o stack LAMP (Linux, Apache, MySQL, PHP) instalado:

* Criar uma instância (máquina virtual): [tutorial](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/EC2_GetStarted.html#ec2-launch-instance)
* Conecte-se a ela usando ssh: [tutorial](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/AccessingInstancesLinux.html)
* Instale o que for necessário (apache, banco de dados e interface gráfica pro banco de dados): [tutorial](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/ec2-lamp-amazon-linux-2.html)



Existem outras opções mais simples, como por exemplo [000webhost](https://www.000webhost.com/)

## Setup do banco de dados

Crie o banco de dados: lado esquerdo do PHPmyAdmin, *new table*, eu dei o nome *IA_demo* (se você mudar o nome deve mudar no código também)

Crie a tabela para organizar os dados:

```sql
 CREATE TABLE `demo_LDR` ( 
     `id` INT NOT NULL AUTO_INCREMENT,
     `LDR1` INT NULL ,
     `LDR2` INT NULL ,
     `button` INT NULL , 
     
     PRIMARY KEY (`id`)
 )
```

## Setup do website

Envie os arquivos usando scp. Exemplo:

```
scp -i <local-da-chave> demo-arduino-IA-IoT/02\ -\ Servidor\ web/* ec2-user@:<endereço-web>/var/www/html/demo/
```

Teste tudo inserindo um dado fake, digintado no navegador (ou seja, fazendo um get request):

```
<endereço-web>/demo/API_data_receive.php?LDR1=150&LDR2=250&button=1
```

# Análise

Linguagens e tecnologias:

* Python: linguagem de programação utilizada
* Jupyter notebook: software para rodar python
* Colaboratory: plataforma online da Google similar ao Jupyter
* Scikit learn, pandas, numpy, matplotlib: bibliotecas para data science
* R, matlab, C++: outras linguagens muito utilizadas

Etapas:

1. Definição do problema
2. Coleta de dados
3. Pré-processamento dos dados
4. Treinar o modelo
5. Avaliar (métricas de classificação, testar novos pontos e visualizar a fronteira de decisão)