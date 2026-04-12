// Exemplo de Fetch API 

const URL = 'https://dummyjson.com/products'

async function chamarAPI(){
    const resp = await fetch(URL)
    if(resp.status === 200){
        var obj = await resp.json()
    }
    console.log(obj)
}

chamarAPI()