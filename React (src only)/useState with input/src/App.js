import './App.css';
import dataUser from './dataUser';
import {useState} from 'react';

function App() {
  const [chosenProfession, setChosenProfession] = useState("Employee")

  console.log("chosen profession is: " + chosenProfession)

  function FilterData()
  {
    const filterUser = dataUser.filter(user => user.profession === chosenProfession)
    const listUser = filterUser.map(user => {
      return(
        <li key={user.ID}>
          Name: {user.name} <br/>
          Age: {user.age} <br/>
          profession: {user.profession} <br/>
        </li>
      )
    })
    return(<ul>{listUser}</ul>)
  }

  return (
    <>
      <h1>Input profession</h1>
      <input 
        type="text" 
        value={chosenProfession}
        onChange={e => setChosenProfession(e.target.value)}
      />
      {/* <input type="submit" onClick={FilterData} /> */}
      <FilterData/>
    </>
  );
}

export default App;
