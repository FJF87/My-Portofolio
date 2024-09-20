import './App.css';
import dataContext from './ContextProvider';
import { Route,Routes,Link } from 'react-router-dom';
import Homepage from './Homepage';
import Profile from './Profile';
import Form from './Form';

const userData = {
  name: "Luke",
  age: 20,
  hobby: "lightsaber training"
}

function App() {
  return(
    <>
      <dataContext.Provider value={userData}>
        <nav>
          <Link to='/'>Homepage</Link><br/>
          <Link to='/Profile'>Profile</Link><br/>
          <Link to='/Form'>Comment</Link>
        </nav>
        <Routes>
            <Route path='/' element={<Homepage/>} />
            <Route path='/Profile' element={<Profile/>} />
            <Route path='/Form' element={<Form/>} />
        </Routes>
      </dataContext.Provider>
    </>
  );
}

export default App;
