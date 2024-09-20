import './App.css';
import {useState} from 'react';

const employee = [
  {
    name: "Andy",
    age: 22,
    status: "unemployed"
  },
  {
    name: "Budi",
    age: 21,
    status: "unemployed"
  },
  {
    name: "Dave",
    age: 23,
    status: "employed"
  },
  {
    name: "John",
    age: 22,
    status: "unemployed"
  },
  {
    name: "Howdy",
    age: 25,
    status: "employed"
  }
];

function App() {
  const [inputName, setInputName] = useState("");

  const employeeData = employee.map(person => {
    const personData = `name is ${person.name} at ${person.age} and his status is ${person.status}`
    return <li>{personData}</li>
  });

  function handleSubmit(e) {
    e.preventDefault();
    let found = false;
    for(let x of employee) {
      if(x.name == inputName) {
        found = true;
        alert(`${x.name} - ${x.age} - ${x.status}`);
      }
    }
    if(found == false) {
      alert("cannot find the name");
    }
    setInputName("");

  }

  return (
    <>
      <div>
        <ul>
          {employeeData}
        </ul>
      </div>
      <form onSubmit={handleSubmit}>
        <input
          id="nameSearch"
          type="text"
          placeholder="enter person name"
          value={inputName}
          onChange={e => setInputName(e.target.value)}
        />
        <button type="submit">get data</button>
      </form>
      <p></p>
    </>
  );
}

export default App;
