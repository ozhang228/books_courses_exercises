import ShowingData from "./exercises/ShowingData"
import { AllCommunityModule, ModuleRegistry } from "ag-grid-community";

ModuleRegistry.registerModules([AllCommunityModule]);

function App() {

  return (
    <>
      <ShowingData></ShowingData>
    </>
  )
}

export default App
