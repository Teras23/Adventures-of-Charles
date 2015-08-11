using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Linq;

public class TileEditor : EditorWindow {

    private Object tilemap;
    private Vector2 selectedTile = new Vector2(0, 0);
    private Object selectTileTexture;
    private static Sprite testSprite;
    private static Object parent;
    private static bool enableGrid = true;
    private static Vector2 gridStart = new Vector2(0, 0);
    private static Vector2 gridLenght = new Vector2(10, 10);

    [MenuItem("Window/Tile Editor")]
    public static void ShowWindow() {
        EditorWindow.GetWindow(typeof(TileEditor));
    }

    void OnGUI() {
        Event evt = Event.current;

        parent = EditorGUILayout.ObjectField("Select parent of tiles:", parent, typeof(GameObject), true);
        enableGrid = EditorGUILayout.Toggle("Enable grid", enableGrid);
        gridStart = EditorGUILayout.Vector2Field("Grid start", gridStart);
        gridLenght = EditorGUILayout.Vector2Field("Grid lenght", gridLenght);
        tilemap = EditorGUILayout.ObjectField("Select Tilemap:", tilemap, typeof(Texture), false);
        selectTileTexture = EditorGUILayout.ObjectField("Select sprite to draw:", selectTileTexture, typeof(Sprite), false);

        if(tilemap != null) {
            Sprite[] sprites = AssetDatabase.LoadAllAssetsAtPath(AssetDatabase.GetAssetPath(tilemap)).Select(x => x as Sprite).Where(x => x != null).ToArray();	

            GUILayout.Label(tilemap as Texture);
            Rect tilemapRect = GUILayoutUtility.GetLastRect();
            testSprite = sprites[0];

            if(evt.isMouse) {
                Vector2 mousePos = evt.mousePosition;
                selectedTile = new Vector2(Mathf.Floor((mousePos.x - tilemapRect.x) / 32), Mathf.Floor((mousePos.y - tilemapRect.y) / 32));
                if(selectedTile.x < 8 && selectedTile.x > -1 && selectedTile.y < 8 && selectedTile.y > -1) {
                    selectTileTexture = sprites[(int)selectedTile.x + (int)selectedTile.y * 8] as Object;
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
        if(evt.type == EventType.mouseDown && evt.button == 0) {
            Vector2 mousePos = Event.current.mousePosition;
            GameObject newTile = new GameObject();
            newTile.AddComponent<SpriteRenderer>();
            newTile.GetComponent<SpriteRenderer>().sprite = testSprite;
            mousePos.y = SceneView.currentDrawingSceneView.camera.pixelHeight - mousePos.y;
            Vector2 realPos = SceneView.currentDrawingSceneView.camera.ScreenPointToRay(mousePos).origin;
            newTile.transform.position = new Vector3(Mathf.Floor(realPos.x / 0.32f) * 0.32f, Mathf.Floor(realPos.y / 0.32f) * 0.32f, 0);
            if(parent != null)
                newTile.transform.parent = (parent as GameObject).transform;
            newTile.name = testSprite.name;
        }
    }
}
