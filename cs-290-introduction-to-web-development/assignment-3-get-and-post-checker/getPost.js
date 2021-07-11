var express = require('express');

var bodyParser = require("body-parser");

var app = express();

var handlebars = require('express-handlebars').create({defaultLayout:'main'});

app.engine('handlebars', handlebars.engine);

app.set('view engine', 'handlebars');

app.set('port', 3319);

app.use(bodyParser.urlencoded({ extended: false }));

app.use(bodyParser.json());

app.get('/',function(req,res)
{
    var queryParameters = [];
	
	for (var p in req.query) 
    {
		queryParameters.push({"name": p, "value": req.query[p]});   
	}
	
	var context = {};
	context.getQueryData = queryParameters;
	res.render("get", context);                                
});

app.post("/", function(req, res)                            
{
	var queryParameters = [];
	
	for (var p in req.query)
    {
		queryParameters.push({"name": p, "value": req.query[p]});   
	}
    
    var bodyParameters = [];
	
	for (var b in req.body) 
    {
		bodyParameters.push({"name": b, "value": req.body[b]});
	}
	var context = {};
	context.queryList = queryParameters;
    context.bodyList = bodyParameters;

	res.render("post", context);                                                  
});


app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log("Express started on 3133");
});