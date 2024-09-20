import { useDataDessert } from './AppState'
import FoodCard from './FoodCard'

export default function FoodListCart() {
  const dataDessert = useDataDessert()
  
  const listOfFood = dataDessert.map(singleDessert => {
      return (<FoodCard
        key={singleDessert["name"]+"Card"}
        singleDessert={singleDessert}
      />)
    })

    return(
      <>
        <div id="dessertMenu">
          <h1 id="mainTitle">Desserts</h1>
          <article id='foodListCart'>
            {listOfFood}
          </article>
        </div>
      </>
    )
}