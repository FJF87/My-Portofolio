import './App.css';
import dataUser from './user';
import {useState} from 'react';

function AddUser(onAddUser)
{
  const [newUser, setNewUser] = useState({name: "", age: 0});

  return(
    <>
      <label>
        <p>New person's name: </p>
        <input
          type='text'
          value={newUser.name}
          onChange={(e) => setNewUser({...newUser, name: e.target.value})}
        />
      </label>
      <br/>
      <label>
        <p>New person's age: </p>
        <input
          type='number'
          value={newUser.age}
          onChange={(e) => setNewUser({...newUser, age: e.target.value})}
        />
      </label>
      <input type='submit' onClick={() => onAddUser(newUser)} />
    </>
  )
}

function App() {
  const [users, setUsers] = useState(dataUser);

  function handleAddUser(userObj)
  {
    setUsers([
      ...users,
      {
        name: userObj.name,
        age: userObj.age
      }
    ])
    console.log("user object is: ");
    console.log(userObj);
  }

  function ShowList()
  {
    const userList = users.map(user => {
      return(
        <li key={user.name}>
          Name: {user.name} <br/>
          Age: {user.age}
        </li>
      )
    })

    return(
      <ul>{userList}</ul>
    )
  }

  return (
    <>
      <h1>Data user</h1>
      <ShowList />
      <AddUser onAddUser={handleAddUser}/>
    </>
  );
}

export default App;
