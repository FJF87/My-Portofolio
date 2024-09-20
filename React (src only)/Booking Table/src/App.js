import './App.css';
import Form from './Form';
import logo from './littleLemonLogo.jpg'

const bodyStyle = {
  margin: "0px",
  padding: "0px",
  display: "grid",
  justifyContent: "center",
  backgroundColor: "rgb(255, 150, 0)"
}

const theFormStyle = {
  margin: "50px",
  padding: "50px",
  display: "grid",
  maxWidth: "200px",
  gap: "20px",
  backgroundColor: "cyan"
}

const headerStyle = {
  display: "grid",
  justifyContent: "center"
}

const mainStyle = {
  display: "grid",
  justifyContent: "center"
}

const imageStyle = {
  margin: "50px",
  width: "200px",
  padding: "50px"
}

const footerStyle = {
  display: "grid",
  justifyContent: "end"
}

function App() {
  return (
    <>
      <body style={bodyStyle}>
        <header style={headerStyle}>
          <h1>Little Lemon Online Reservation</h1>
        </header>
        <main style={mainStyle}>
          <img  style={imageStyle} src={logo} alt='Little Lemon Logo'></img>
          <form style={theFormStyle}>
            <Form />
          </form>
        </main>
        <footer style={footerStyle}>
            <h5>@Little Lemon 2024</h5>
        </footer>
      </body>
    </>
  );
}

export default App;
// style="display: grid; max-width: 200px; gap: 20px"