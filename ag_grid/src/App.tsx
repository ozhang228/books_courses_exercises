import QuickStart from "./QuickStart"
import { AllCommunityModule, ModuleRegistry } from "ag-grid-community";

ModuleRegistry.registerModules([AllCommunityModule]);

function App() {

  return (
    <>
      <QuickStart></QuickStart>
    </>
  )
}

export default App
