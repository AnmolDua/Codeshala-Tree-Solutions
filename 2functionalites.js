//creation of first node and algo creation for encryption
var CryptoJS = require("crypto-js");

function encrypt(obj,NodeId){
// Encrypt
// console.log(obj);
var ciphertext = CryptoJS.AES.encrypt(JSON.stringify(obj),NodeId);

// console.log(ciphertext.toString());
return ciphertext.toString();
// Decrypt

}


function decrypt(ciphertext,NodeId){
// console.log(ciphertext);
// console.log(NodeId);
  var bytes  = CryptoJS.AES.decrypt(ciphertext.toString(), NodeId);
  var decryptedData = JSON.parse(bytes.toString(CryptoJS.enc.Utf8));
  // console.log('decrypt = '+decryptedData);
  return decryptedData;

}



module.exports={encrypt:encrypt,decrypt:decrypt};

var uniqid = require('uniqid');
var crypto = require('crypto');
var Encrypt=  require('./encrypter');

class Person{
constructor(name,address,mobile,value){
this.name=name;
this.address=address;
this.mobile=mobile;
this.value=value;
}


}

let NodeNumber=0; // will come from db;

class Node{
constructor(){

  this.dateTime= (new Date).getTime();
  this.NodeId=uniqid();

  this.childNodeId=[];
}

}


function createNode(name,address,mobile,value){
  let obj=new Node();
  let data=new Person(name,address,mobile,value);

  obj.data=Encrypt.encrypt(data,obj.NodeId);
  obj.NodeNumber=NodeNumber;
  NodeNumber+=1;
  // store obj in database
  return obj;
}


obj=createNode("Anmol","Faridabad","8130932912","12");
console.log(obj);

obj.data=Encrypt.decrypt(obj.data,obj.NodeId);
console.log(obj);



















