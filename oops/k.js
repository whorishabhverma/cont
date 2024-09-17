// make an array of objects store  keys and respective  values as name and price of a product  in each object, now return a new object having the keys same and increase the price by 10%
const arr = [
    {"name":"kurkure", "category" : "chips",  "price":120 },
    {"name":"kurk1",   "category" : "chips", "price":122 },
    {"name":"kurk",    "category" : "chips", "price":180 }
];
const newArr =  arr.map(function (item){
    return {
        ...item,
        price :  (item.price  * 1.10).toFixed(2)
    }
})

// higher order function : jb function ke andr function paas krte h
// jo andr waala function h use : callback 
// A higher-order function is a function that can do at least one of the following:
// Takes one or more functions as arguments.
// const newArr =  arr.map((item)=>{
//     return {
//         name :  item.name,
//         price :  (item.price  * 1.10).toFixed(2)
//     }
// })

console.log(newArr)
// const arr1 = [1,2,3,4,5];
// const newArr = arr1.map((item)=>{
//     return item*item;
// })
