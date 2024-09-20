import { useContext } from "react"
import dataContext from "./ContextProvider"

function Homepage() {
    const data = useContext(dataContext);
    return(
        <div>
            <h1>Welcome</h1>
            <h2>{data.name}</h2>
        </div>
    )
}

export default Homepage;