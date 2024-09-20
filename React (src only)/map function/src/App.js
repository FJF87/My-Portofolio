import './App.css';
import dataUser from './DataUser'

function ShowData()
{
  console.log(dataUser)
  const listData = dataUser.map(user => {
    return(
      <li key={user.ID}>
        <h3>Name: {user.name}</h3>
        <h4>Age: {user.age}</h4>
        <h4>Profession: {user.profession}</h4>
        <br/>
      </li>
    )
  })

  return(
      <ul>
        {listData}
      </ul>
  )
}

function App() {
  // const [data, setData] = useState(dataUser)

  // function addData(e)
  // {
  //   e.preventDefault
  // }

  return (
    <>
      <h1>Hello</h1>
      <ShowData/>
      {/* <form onSubmit={addData}>
        <input type="text" name="name"/>
        <input type="number" name="age" />
        <input type="text" name="profession" />
        <input type="submit" value="Add data" />
      </form>
      <br/>
      <button onclick={() => showData}>show data</button> */}
    </>
  );
}

export default App;
