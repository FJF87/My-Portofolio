import { useContext } from "react"
import dataContext from "./ContextProvider"

function Profile() {
    const data = useContext(dataContext);
    return(
        <div>
            <h1>Profile</h1>
            <table>
                <tbody>
                    <tr>
                        <td>Name</td>
                        <td>{data.name}</td>
                    </tr>
                    <tr>
                        <td>Age</td>
                        <td>{data.age}</td>
                    </tr>
                    <tr>
                        <td>Hobby</td>
                        <td>{data.hobby}</td>
                    </tr>
                </tbody>
            </table>
        </div>
    )
}

export default Profile;