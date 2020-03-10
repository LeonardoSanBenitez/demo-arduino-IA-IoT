new Vue({
    el: '#app',
    data: {
        json: null
    },
    created: function () {
        // Recarrega a tabela a cada 3 segundos
		this.requestData();
		window.setInterval(this.requestData, 3000);
    },
	methods: {
		requestData(){
            //Acessa a API para ler os dados do Banco de Dados
			var _this = this;
			$.getJSON('API_data_request.php', function (json) {
				_this.json = json;
			});
			console.log("Data requested");
		}
	}
});
