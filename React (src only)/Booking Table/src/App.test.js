import { render, screen } from '@testing-library/react';
import App from './App';

test('renders booking form heading', () => {
  render(<Form />);
  const linkElement = screen.getByText("Online Reservation");
  expect(linkElement).toBeInTheDocument();
});
