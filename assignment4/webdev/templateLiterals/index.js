const users = [
     {name:"Alice", age:53},
    {name:"Tim", age:74}

]
function getTemplate(user){
    let str = '';
    Object.keys(user).map((key)=>{
        str+=`\t<td>${user[key]}</td>\n`
    })
    return str;
}
function getBody(users){
    let template = ``;
    users.map((users)=>{
        const output = getTemplate(users);
        template+= `<tr>\n${output}</tr>\n`
    })
    return template;
}
const element = document.getElementById("users");
element.innerHTML= getBody(users);
console.log("users populated")