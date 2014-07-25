var EventSource = require('eventsource');
// Twilio Credentials 
var accountSid = process.env.TWILIO_ACCOUNT_SID; 
var authToken = process.env.TWILIO_AUTH_TOKEN;
var destphone = process.env.DEST_PHONE;
var message = process.env.MESSAGE;

var esInitDict = {rejectUnauthorized: false};

var deviceID = process.env.SPARK_CORE_ID;
var accessToken = process.env.SPARK_ACCESS_TOKEN;

var url = "https://api.spark.io/v1/devices/"+deviceID+"/events/?access_token="+accessToken;

console.log("Listening on "+url+" ...");

var es = new EventSource(url);

es.addEventListener('motion', function(e){
	console.log( e.data);
	//require the Twilio module and create a REST client 
	var client = require('twilio')(accountSid, authToken); 
 
	client.messages.create({  
		from: "+16176741235",    
		    to: destphone,  
				body: message,   
				}, function(err, message) { 
			    console.log(message.sid); 
			});
	   
   
}, false);