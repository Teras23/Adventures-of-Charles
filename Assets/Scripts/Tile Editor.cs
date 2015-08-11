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

    [MenuItem("Window/Tile Editor")]
    public static void ShowWindow() {
        EditorWindow.GetWindow(typeof(TileEditor));
    }

    void OnGUI() {
        Event evt = Event.current;

        parent = EditorGUILayout.ObjectField("Select parent of tiles:", parent, typeof(GameObject), true);
        tilemap = EditorGUILayout.ObjectField("Select Tilemap:", tilemap, typeof(Texture), false);
        selectTileTexture = EditorGUILayout.ObjectField("Select sprite to draw:", selectTileTexture, typeof(Sprite), false);

        if(tilemap != null) {
            Sprite[] sprites = AssetDatabase.LoadAllAssetsAtPath(AssetDatabase.GetAssetPath(tilemap)).OfType<Sprite>().ToArray();
            GUILayout.Label(tilemap as Texture);
            Rect tilemapRect = GUILayoutUtility.GetLastRect();
            testSprite = sprites[0];

            if(evt.isMouse) {
                Vector2 mousePos = evt.mousePosition;
                selectTileTexture = sprites[(int)selectedTile.x] as Object;
                selectedTile = new Vector2(Mathf.Floor((mousePos.x - tilemapRect.x) / 32), Mathf.Floor((mousePos.y - tilemapRect.y) / 32));
            }
        }
    }

    [DrawGizmo(GizmoType.NotInSelectionHierarchy)]
    static void RenderCustomGizmo(Transform objectTransform, GizmoType gizmoType) {
        int lineamount = 50;
        int linelenght = 100;

        for(int i = 0; i < 10; ++i) {
            Gizmos.DrawLine(new Vector3(-linelenght, 0.32f * i, 0), new Vector3(linelenght, 0.32f * i, 0));
        }

        for(int i = 0; i < 10; ++i) {
            Gizmos.DrawLine(new Vector3(0.32f * i, -linelenght, 0), new Vector3(0.32f * i, linelenght, 0));
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
