using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Linq;


[System.Serializable]
public class TileEditor : EditorWindow {

    public Object tilemap;
    public Vector2 selectedTile = new Vector2(0, 0);
    public static GameObject selectTileTexture;
    public static Object parent;
    public string parentName;
    public static bool enableGrid = true;
    public static Vector2 gridStart = new Vector2(0, 0);
    public static Vector2 gridLenght = new Vector2(10, 10);
    public static bool editmode = false;
    [SerializeField]
    public static int layers;
    [SerializeField]
    public static int currentLayer;
    public string prefabFolder;
    public Sprite[] sprites;

    [MenuItem("Window/Tile Editor")]
    public static void ShowWindow() {
        EditorWindow.GetWindow(typeof(TileEditor));
    }

    void OnGUI() {
        Event evt = Event.current;

        parentName = EditorGUILayout.TextField("Parent name", parentName);
        prefabFolder = EditorGUILayout.TextField("Prefabs' location", prefabFolder);
        parent = EditorGUILayout.ObjectField("Select parent of tiles:", parent, typeof(GameObject), true);
        enableGrid = EditorGUILayout.Toggle("Enable grid", enableGrid);
        editmode = EditorGUILayout.Toggle("Enable editing", editmode);
        gridStart = EditorGUILayout.Vector2Field("Grid start", gridStart);
        gridLenght = EditorGUILayout.Vector2Field("Grid lenght", gridLenght);
        layers = EditorGUILayout.IntField("Amount of layers", layers);
        currentLayer = EditorGUILayout.IntSlider("Current layer", currentLayer, 0, layers - 1);

        tilemap = EditorGUILayout.ObjectField("Select Tilemap:", tilemap, typeof(Texture), false);

        if(selectTileTexture != null)
            GUILayout.Label(selectTileTexture.name);

        if(GUILayout.Button("Create prefabs")) {
            //check if folder is there if not create required folders
            foreach(Sprite tile in sprites) {
                GameObject tilePrefab = new GameObject();
                tilePrefab.AddComponent<SpriteRenderer>().sprite = tile;
                PrefabUtility.CreatePrefab("Assets/" + prefabFolder + "/" + tilemap.name + "/" + tile.name + ".prefab", tilePrefab);
                Object.DestroyImmediate(tilePrefab);
            }
        }

        if(parent == null && parentName != null) {
            parent = GameObject.Find(parentName);
        }
        //remove objectfield and make gameobject if there is none, but name exists

        if(parent != null) {
            if(layers < (parent as GameObject).transform.childCount) {
                layers = (parent as GameObject).transform.childCount;
            }
            else if(layers > (parent as GameObject).transform.childCount) {
                for(int i = 0; i < layers - (parent as GameObject).transform.childCount; ++i) {
                    GameObject layer = new GameObject("Layer " + (i + layers - 1));
                    layer.transform.parent = (parent as GameObject).transform;
                }
            }
        }

        if(tilemap != null) {
            sprites = AssetDatabase.LoadAllAssetsAtPath(AssetDatabase.GetAssetPath(tilemap)).Select(x => x as Sprite).Where(x => x != null).ToArray();	

            GUILayout.Label(tilemap as Texture);
            Rect tilemapRect = GUILayoutUtility.GetLastRect();

            if(evt.isMouse) {
                Vector2 mousePos = evt.mousePosition;
                selectedTile = new Vector2(Mathf.Floor((mousePos.x - tilemapRect.x) / 32), Mathf.Floor((mousePos.y - tilemapRect.y) / 32));
                if(selectedTile.x < 8 && selectedTile.x > -1 && selectedTile.y < 8 && selectedTile.y > -1) {
                    int tilenum = (int)selectedTile.x + (int)selectedTile.y * 8;
                    selectTileTexture = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/" + prefabFolder + "/" + tilemap.name + "/" + tilemap.name + "_" + tilenum + ".prefab");
                    Repaint();
                }
            }
        }
    }

    [DrawGizmo(GizmoType.NotInSelectionHierarchy)]
    static void RenderCustomGizmo(Transform objectTransform, GizmoType gizmoType) {

        if(enableGrid) { 
            for(int i = 0; i < gridLenght.y / 0.32f; ++i) {
                Gizmos.DrawLine(new Vector3(gridStart.x, 0.32f * i, 0), new Vector3(gridLenght.x, 0.32f * i, 0));
            }

            for(int i = 0; i < gridLenght.x / 0.32f; ++i) {
                Gizmos.DrawLine(new Vector3(0.32f * i, gridStart.y, 0), new Vector3(0.32f * i, gridLenght.y, 0));
            }
        }
    }

    void OnEnable() {
        SceneView.onSceneGUIDelegate += OnSceneGUI;
    }
    void OnDisable() {
        SceneView.onSceneGUIDelegate -= OnSceneGUI;
    }

    static void OnSceneGUI(SceneView aView) {
        Event evt = Event.current;
        if(evt.type == EventType.mouseDown && evt.button == 0 && editmode && selectTileTexture != null) {
            //HandleUtility.AddDefaultControl(GUIUtility.GetControlID(FocusType.Passive));
            Vector2 mousePos = Event.current.mousePosition;
            GameObject newTile = PrefabUtility.InstantiatePrefab(selectTileTexture) as GameObject;
            mousePos.y = SceneView.currentDrawingSceneView.camera.pixelHeight - mousePos.y;
            Vector2 realPos = SceneView.currentDrawingSceneView.camera.ScreenPointToRay(mousePos).origin;
            newTile.transform.position = new Vector3((int)Mathf.Floor(realPos.x / 0.32f) * 0.32f, Mathf.Floor(realPos.y / 0.32f) * 0.32f, -currentLayer);
            if(parent != null)
                newTile.transform.parent = GameObject.Find("Layer " + currentLayer).transform;
            newTile.name = selectTileTexture.name;
            newTile.GetComponent<SpriteRenderer>().sortingOrder = currentLayer;
        }
    }
}
