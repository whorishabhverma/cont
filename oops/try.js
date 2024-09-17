const products = [
  { id: 1, name: 'Laptop', price: 1000, category: 'Electronics' },
  { id: 2, name: 'Book', price: 20, category: 'Books' },
  { id: 3, name: 'Smartphone', price: 500, category: 'Electronics' },
  { id: 4, name: 'Desk Chair', price: 150, category: 'Furniture' },
  { id: 5, name: 'Tablet', price: 300, category: 'Electronics' },
  { id: 6, name: 'Notebook', price: 5, category: 'Stationery' },
  { id: 7, name: 'Printer', price: 200, category: 'Electronics' }
];


const processProducts = (products) => {
  return products
    .filter(function (product){return product.category === 'Electronics'})
};

const result = processProducts(products);
const ans = result.map((product)=>{
    return {
    ...product,
      price: product.price * 1.15,
      discountPrice: product.price * 1.15 * 0.9}
})
console.log(ans);