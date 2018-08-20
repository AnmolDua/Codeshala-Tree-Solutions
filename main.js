//apart from other two functionalities implemented try to do extend that solution
var CryptoJS = require("crypto-js");

var MultiSet = require('mnemonist/multi-set');
function encrypt(obj,NodeId){
// Encrypt
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
var set=new MultiSet();
class Person{
constructor(name,address,mobile,value){
this.name=name;
this.address=address;
this.mobile=mobile;
this.value=value;
}


}

let NodeNumber=0; // will come from db;
var rootAddress=NULL;
var previousNodeNumber=-1;
class Node{
constructor(){

  this.dateTime= (new Date).getTime();
  this.NodeId=uniqid();
  this.childNodeId=[];
  this.NodeNumber;
  this.ReferenceNodeId;
  this.NodeId;
  this.referenceChildNodeId=[];
}

}


function createNode(name,address,mobile,value){
  let obj=new Node();
  let data=new Person(name,address,mobile,value);
  obj.data=Encrypt.encrypt(data,obj.NodeId);
  obj.NodeNumber=NodeNumber;
  obj.referenceChildNodeId.push(obj);
  if(NodeNumber==0){
      obj.ReferenceNodeId=null;
      //creating a multiset here at the root node
      set.add(obj);
  }
  else
  {
    if(previousNodeNumber==NodeNumber-1){
        obj.ReferenceNodeId=rootAddress[NodeNumber-1];
        obj.ReferenceChildNodeId=NULL;
        obj.NodeId=uniqueid();
       }    
  }
  NodeNumber+=1;
  previousNodeNumber=NodeNumber;
  // store obj in database
  return obj;
}
function insertatparticularposition(NodeId,name,address,mobile,value){
    set.forEach(function(value) {
      //console.log(value);
      if(value==NodeId){
       var childobj= createNode(name,address,mobile,value);
        childobj.ReferenceNodeId=
       }
     });
    }


obj=createNode("Anmol","Delhi","8130932912","1");
console.log(obj);
obj.data=Encrypt.decrypt(obj.data,obj.NodeId);
console.log(obj);

obj.insertatparticularposition("Anmol","Delhi","8130932912","1","2");


