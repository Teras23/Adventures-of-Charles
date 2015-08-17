#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Linq;


[System.Serializable]
public class TileEditor : EditorWindow {

    public bool showProjectSettings;

    public bool showEditorSettings;
    public static bool enableGrid;
    public static bool editmode;

    public Object tilemap;
    public Vector2 selectedTile = new Vector2(0, 0);
    public static GameObject selectTileTexture;
    public static Object parent;
    public string parentName;
    public static Vector2 gridStart = new Vector2(0, 0);
    public static Vector2 gridLenght = new Vector2(10, 10);
    public static int layers;
    public static int currentLayer;
    public string prefabFolder;
    public Sprite[] sprites;
    public int tileSize;

    [MenuItem("Window/Tile Editor")]
    public static void ShowWindow() {
        EditorWindow.GetWindow(typeof(TileEditor));
    }

    void OnGUI() {
        Event evt = Event.current;

        showProjectSettings = EditorGUILayout.Foldout(showProjectSettings, "Project settings");

        if(showProjectSettings) {
            EditorGUI.indentLevel++;
            layers = EditorGUILayout.IntField("Amount of layers", layers);
            tileSize = EditorGUILayout.IntField("Size of tiles on screen", tileSize);
            parentName = EditorGUILayout.TextField("Parent name", parentName);
            prefabFolder = EditorGUILayout.TextField("Prefabs' location", prefabFolder);
            parent = EditorGUILayout.ObjectField("Select parent of tiles:", parent, typeof(GameObject), true);
            EditorGUI.indentLevel--;
        }
        EditorGUILayout.Space();

        showEditorSettings = EditorGUILayout.Foldout(showEditorSettings, "Editor settings");

        if(showEditorSettings) {
            EditorGUI.indentLevel++;
            enableGrid = EditorGUILayout.Toggle("Enable grid", enableGrid);
            editmode = EditorGUILayout.Toggle("Enable editing", editmode);
            EditorGUI.indentLevel--;
        }

        EditorGUILayout.Space();

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

        Vector2 start = SceneView.currentDrawingSceneView.camera.ScreenToWorldPoint(Vector3.zero);
        Vector2 end = SceneView.currentDrawingSceneView.camera.ScreenToWorldPoint(new Vector3(SceneView.currentDrawingSceneView.camera.pixelWidth, SceneView.currentDrawingSceneView.camera.pixelHeight, 0));

        if(enableGrid && SceneView.currentDrawingSceneView.in2DMode) {
            for(int i = 0; i < end.x - start.x; ++i) {
                Gizmos.DrawLine(new Vector3((int)start.x + i, start.y, 0), new Vector3((int)start.x + i, end.y, 0));
            }

            for(int i = 0; i < end.y - start.y; ++i) {
                Gizmos.DrawLine(new Vector3(start.x, (int)start.y + i, 0), new Vector3(end.x, (int)start.y + i, 0));
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
#endif