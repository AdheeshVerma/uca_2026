const data = [ 
  "First Name", 
  "Last Name", 
  "Email"
];

function getBody(data){
    let template = ``;
    data.map((data)=>{
        
        template+= `<label>\n${data}</label>\n<input type="text" />\n`
    })
    return template;
}
const element = document.getElementById("userForm");
console.log(getBody(data))
element.innerHTML= getBody(data);
console.log("data populated")