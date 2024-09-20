import './App.css';
import FoodListCart from './FoodListCard';
import CartItemList from './CartItemList';
import OrderConfirmation from './OrderConfirmation';
import AppState from './AppState';

function App() {
  console.log(window.innerWidth)

  return(
    <>
      <AppState>
        <OrderConfirmation/>
        <main>
          <FoodListCart/>
          <CartItemList/>
        </main>
      </AppState>
    </>
  )
}

export default App;
