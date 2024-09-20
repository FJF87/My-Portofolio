import React, {useState} from 'react';
import ThemeContext from './Context';
import ThemeSwitcher from './ThemeSwitcher';

function App() {
  const [theme, setTheme] = useState('light');

  return(
    <ThemeContext.Provider value={{theme, setTheme}}>
      <ThemeSwitcher/>
    </ThemeContext.Provider>
  )
}

export default App;